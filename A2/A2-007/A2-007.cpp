/*
 * A2-007: Neutrino Trap Tank (ถังดักนิวตริโน)
 *
 * Problem:
 *   N square tanks are placed with no partial overlap (only nesting allowed).
 *   Each tank i is described by its min x-coord Ai and max x-coord Bi (Ai < Bi).
 *   Tanks are sorted by Ai ascending. If tank i contains tank j, picking tank i
 *   also picks tank j (they count as 1 "pick").
 *
 *   Given M required tanks to remove, find:
 *   1. The minimum number of picks (where picking a tank picks its whole nested group).
 *   2. Among all minimum-pick solutions, minimize the number of irrelevant tanks taken.
 *   3. Output the picks in ascending order of tank number.
 *
 * Approach:
 *   - Build a forest of containment: tank p is the direct parent of tank c if p
 *     contains c and there is no other tank between them.
 *   - For each required tank, we must pick some ancestor (or itself). The "root"
 *     of its containment chain that we pick determines what we carry out.
 *   - We want to cover all M required tanks with minimum picks.
 *     Since tanks are nested (tree structure), picking a tank covers all required
 *     tanks in its subtree.
 *   - Strategy:
 *       For each required tank, find its ancestors (chain to root).
 *       We need a set of tanks S (each S_i is an ancestor-or-self of some required tank)
 *       such that every required tank is "covered" by some member of S, with minimum |S|,
 *       then minimum total subtree size of members of S.
 *
 *   Key insight: tanks form a forest. We must pick a set of nodes that covers all M
 *   required nodes. Two required nodes covered by the same pick must be in the same
 *   subtree of the picked node (i.e., the picked node is a common ancestor).
 *
 *   Algorithm:
 *   1. Sort tanks by Ai (already given sorted).
 *   2. Build parent array: parent[i] = direct containing tank of i, or -1.
 *   3. For each required tank, find its "chain" of ancestors up to root.
 *   4. We greedily pick the highest ancestor that covers the maximum required tanks,
 *      then the second, etc. — but this is complex for the secondary objective.
 *
 *   Simpler correct approach (N <= 300):
 *   - A tank X "covers" required tank r if X is an ancestor-or-equal of r.
 *   - We want minimum set of tanks {X1, X2, ...} such that every required tank
 *     is covered by some Xi.
 *   - This is a set cover, but with tree structure it simplifies:
 *     For each required tank r, its valid "pickers" are: r itself and all its ancestors.
 *     Two required tanks r1, r2 can be covered by the same pick X only if X is an
 *     ancestor (or equal) of both, i.e., X contains both → X contains the "larger" one
 *     in the nesting order.
 *
 *   Since the nesting is a forest, the minimum number of picks = number of connected
 *   components of required tanks when we look at "can they share a picker?"
 *   Two required tanks can share a picker iff one is an ancestor of the other
 *   (direct or indirect). So we group required tanks that are in ancestor-descendant
 *   relationships and each group needs exactly 1 pick.
 *
 *   For each group, we want to pick the shallowest common ancestor that covers all
 *   required tanks in the group with minimum extra tanks (i.e., minimum subtree size).
 *   But actually since it's a tree, required tanks in the same "chain" share ancestors.
 *
 *   Revised algorithm:
 *   - Build the containment forest.
 *   - Mark required tanks.
 *   - Each required tank that has no required ancestor must be "picked" at some level.
 *   - Min picks = number of required tanks that have no required ancestor
 *     (i.e., roots of required subtrees in the forest of required tanks).
 *     Wait, that's not right either because we can pick a non-required ancestor.
 *
 *   Let me think again. We pick any tank (not necessarily required). Picking tank X
 *   covers all required tanks in subtree(X). We want minimum number of picks to cover
 *   all M required tanks, then minimum total number of tanks moved.
 *
 *   This is weighted set cover on a tree:
 *   - Candidates for picks: any tank.
 *   - Cost of pick X = 1 (primary), size_of_subtree(X) (secondary tie-break).
 *   - We need all M required tanks covered.
 *
 *   Since N<=300, we can do DP on the forest:
 *   dp[v] = (min_picks, min_extra_tanks) to handle all required tanks in subtree(v),
 *           given that v is NOT picked by an ancestor.
 *
 *   For each node v:
 *   Option A: Pick v itself → covers all required in subtree(v). Cost: (1, subtree_size(v)).
 *   Option B: Don't pick v, recurse to children. Cost: sum of dp[child] for all children.
 *             (Only children with required tanks in their subtree need to be handled.)
 *   Choose whichever gives lexicographically smaller (picks, extra_tanks).
 *
 *   "extra_tanks" = total tanks moved - M (so minimize tanks moved = minimize extra).
 *   When we pick v: tanks moved = subtree_size(v), required covered = req_in_subtree(v).
 *   extra = subtree_size(v) - req_in_subtree(v).
 *
 *   We track which nodes are actually picked (reconstruction).
 *
 *   Implementation:
 *   - Build tree, compute subtree sizes and req_in_subtree.
 *   - DP bottom-up.
 *   - Reconstruct picks.
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[305], B[305];   // 1-indexed
int par[305];         // direct parent, 0 = no parent (root)
vector<int> children[305];
bool required[305];
int subtree_size[305];
int req_in_subtree[305];

// dp_picks[v], dp_extra[v]: min picks and min extra tanks for subtree of v
// (assuming v's subtree is not covered by an ancestor pick)
int dp_picks[305], dp_extra[305];
bool pick_here[305]; // whether we pick v in optimal solution

void dfs(int v) {
    subtree_size[v] = 1;
    req_in_subtree[v] = required[v] ? 1 : 0;
    for (int c : children[v]) {
        dfs(c);
        subtree_size[v] += subtree_size[c];
        req_in_subtree[v] += req_in_subtree[c];
    }

    if (req_in_subtree[v] == 0) {
        // No required tanks here — no picks needed
        dp_picks[v] = 0;
        dp_extra[v] = 0;
        pick_here[v] = false;
        return;
    }

    // Option A: pick v
    int a_picks = 1;
    int a_extra = subtree_size[v] - req_in_subtree[v];

    // Option B: recurse to children (don't pick v)
    int b_picks = 0, b_extra = 0;
    if (required[v]) {
        // v itself is required and not picked by a child → we'd need a pick for v
        // Actually if we don't pick v, v itself must be covered by a child?
        // No — v can only be covered by v or an ancestor.
        // In the DP, "not picking v" means v is covered by some ancestor.
        // But in this DP, we assume v is NOT covered by an ancestor.
        // So if required[v] is true and we don't pick v, it's uncovered → invalid.
        // Hence option B requires picking v if required[v]? No:
        // option B = handle children independently, but v itself must be picked
        // separately if it's required. But "picking v" covers v and its subtree.
        // If we don't pick v, we need v to be covered somehow → impossible without
        // an ancestor. So if required[v], we must pick something that covers v.
        // The only candidates in this subtree are v itself.
        // So: if required[v], option B is invalid (we must pick v or higher).
        // Since this DP assumes no ancestor covers us, we must pick v.
        b_picks = INT_MAX;
        b_extra = INT_MAX;
    } else {
        for (int c : children[v]) {
            if (req_in_subtree[c] == 0) continue;
            b_picks += dp_picks[c];
            b_extra += dp_extra[c];
        }
    }

    // Choose better option (lexicographically smaller (picks, extra))
    bool prefer_a;
    if (b_picks == INT_MAX) {
        prefer_a = true;
    } else if (a_picks < b_picks) {
        prefer_a = true;
    } else if (a_picks > b_picks) {
        prefer_a = false;
    } else {
        // tie on picks, compare extra
        prefer_a = (a_extra <= b_extra);
    }

    if (prefer_a) {
        dp_picks[v] = a_picks;
        dp_extra[v] = a_extra;
        pick_here[v] = true;
    } else {
        dp_picks[v] = b_picks;
        dp_extra[v] = b_extra;
        pick_here[v] = false;
    }
}

vector<int> result;

void collect(int v) {
    if (req_in_subtree[v] == 0) return;
    if (pick_here[v]) {
        result.push_back(v);
    } else {
        for (int c : children[v]) {
            collect(c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    // Read M required tank indices
    for (int j = 0; j < M; j++) {
        int x; cin >> x;
        required[x] = true;
    }

    // Build containment forest
    // Tanks are sorted by Ai ascending (given in problem).
    // Tank p directly contains tank c if A[p] < A[c] and B[c] < B[p]
    // and there's no other tank q with A[p]<A[q]<A[c] and B[c]<B[q]<B[p].
    // Since N<=300, O(N^2) is fine.
    // Direct parent of c = smallest tank (by width) that contains c.

    fill(par+1, par+N+1, 0);
    for (int c = 1; c <= N; c++) {
        int best = 0;
        int best_width = INT_MAX;
        for (int p = 1; p <= N; p++) {
            if (p == c) continue;
            if (A[p] < A[c] && B[c] < B[p]) {
                int w = B[p] - A[p];
                if (w < best_width) {
                    best_width = w;
                    best = p;
                }
            }
        }
        par[c] = best;
        if (best != 0) children[best].push_back(c);
    }

    // Virtual root 0 collects all actual roots
    for (int i = 1; i <= N; i++) {
        if (par[i] == 0) children[0].push_back(i);
    }

    // DFS from virtual root
    // Set up virtual root
    subtree_size[0] = 0;
    req_in_subtree[0] = 0;
    dp_picks[0] = 0;
    dp_extra[0] = 0;
    pick_here[0] = false;

    for (int root : children[0]) {
        dfs(root);
        dp_picks[0] += dp_picks[root];
        dp_extra[0] += dp_extra[root];
    }

    // Collect result
    for (int root : children[0]) {
        collect(root);
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < (int)result.size(); i++) {
        if (i) cout << " ";
        cout << result[i];
    }
    cout << "\n";

    return 0;
}