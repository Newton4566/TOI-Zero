#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Segment: from (x1,y1) to (x2,y2), y is 0 or 1
struct Seg {
    ll x1, y1, x2, y2;
};

// Cross product of vectors (b-a) and (c-a)
ll cross(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

// Check if point (px,py) is on segment (x1,y1)-(x2,y2)
// (assuming collinear)
bool onSeg(ll x1, ll y1, ll x2, ll y2, ll px, ll py) {
    return min(x1,x2) <= px && px <= max(x1,x2) &&
           min(y1,y2) <= py && py <= max(y1,y2);
}

bool intersects(const Seg& a, const Seg& b) {
    ll d1 = cross(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
    ll d2 = cross(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);
    ll d3 = cross(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
    ll d4 = cross(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;

    // Collinear cases (endpoint on segment)
    if (d1 == 0 && onSeg(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1)) return true;
    if (d2 == 0 && onSeg(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2)) return true;
    if (d3 == 0 && onSeg(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1)) return true;
    if (d4 == 0 && onSeg(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ll> R(N), B(M);
    for (int i = 0; i < N; i++) cin >> R[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    // Build segments for red beam
    // Starts at (0, 0), then R[0] at y=1, R[1] at y=0, ...
    // Point i: x=R[i-1] (or 0), y = i%2
    // Segment i: from point i to point i+1
    auto getY = [](int idx) -> ll { return idx % 2; };

    vector<Seg> red, blue;

    // Red: N+1 points (including origin), N segments
    {
        ll px = 0; ll py = 0;
        for (int i = 0; i < N; i++) {
            ll nx = R[i], ny = getY(i + 1);
            red.push_back({px, py, nx, ny});
            px = nx; py = ny;
        }
    }

    // Blue: M+1 points (including origin), M segments
    {
        ll px = 0; ll py = 0;
        for (int i = 0; i < M; i++) {
            ll nx = B[i], ny = getY(i + 1);
            blue.push_back({px, py, nx, ny});
            px = nx; py = ny;
        }
    }

    // Count intersections
    // The origin (0,0) is a shared start — count it once
    ll ans = 1; // Both beams start at same point (0,0)

    // For all other intersections, use segment-segment intersection
    // But skip counting the shared origin again
    // Strategy: count all intersections, then handle origin carefully
    // Actually: count intersections between segment pairs
    // Origin is endpoint of red[0] and blue[0], counted once already
    // Avoid double-counting shared endpoints

    // Use a set to track intersection points? 
    // Problem says no overlapping segments, so endpoints may coincide
    // but segments won't overlap. We count distinct intersection EVENTS.
    // 
    // Actually re-reading: count number of times beams cross.
    // Each intersection between a red segment and blue segment = 1 crossing.
    // Shared origin counts as 1. Shared endpoints at other positions also count.
    // But problem guarantees no segment overlap, so just count all pairs.
    
    // Reset: Let's count including origin properly
    ans = 0;
    
    // Collect all intersection points to deduplicate endpoint meetings
    // Since no overlap guaranteed, two segments can share at most one point.
    // Two segments from different beams meeting at a boundary point:
    // that point might be end of seg i and start of seg i+1 for one beam,
    // and some point on a segment of the other beam.
    // The problem says "meeting at boundary counts as intersection."
    // We count each geometric intersection point once.
    
    // Use a set of rational points? Coords can be rational.
    // Simpler: since y is 0 or 1, intersection x can be computed exactly
    // as a fraction. Store as pair<ll,ll> (numerator, denominator) reduced.
    
    set<pair<ll,ll>> pts; // x-coordinate as reduced fraction (num, den), y implicit
    // Actually both beams travel between y=0 and y=1, and two segments
    // intersect at a unique point. Since y in {0,1} for endpoints:
    // If both endpoints at same y, segments are horizontal (impossible since 
    // consecutive reflection points differ in y). 
    // Each segment goes from y=0 to y=1 or vice versa.
    // Two segments from different beams: both diagonal.
    // Intersection x = can compute analytically.
    
    // Let's just count pairs of segments that intersect,
    // but deduplicate by intersection point.
    // Intersection point x for seg a=(x1,0)->(x2,1) and b=(x3,0)->(x4,1):
    // They go same direction in y, so they don't cross (parallel in y).
    // Seg a=(x1,0)->(x2,1) and b=(x3,1)->(x4,0): opposite y directions, may cross.
    
    // Key insight: two segments intersect only if one goes 0->1 and other goes 1->0
    // OR they share an endpoint on y=0 or y=1.
    
    // For opposite direction segments:
    // a: (x1, 0) -> (x2, 1), parameterized as (x1 + t*(x2-x1), t), t in [0,1]
    // b: (x3, 1) -> (x4, 0), parameterized as (x3 + s*(x4-x3), 1-s), s in [0,1]
    // Intersection: t = 1-s => t+s=1
    // x1 + t*(x2-x1) = x3 + s*(x4-x3)
    // x1 + t*(x2-x1) = x3 + (1-t)*(x4-x3)
    // x1 + t*(x2-x1) = x3 + x4 - x3 - t*(x4-x3)
    // x1 + t*(x2-x1) = x4 - t*(x4-x3)
    // t*(x2-x1) + t*(x4-x3) = x4 - x1
    // t*((x2-x1)+(x4-x3)) = x4 - x1
    // t = (x4-x1) / ((x2-x1)+(x4-x3))
    // Intersection x = x1 + t*(x2-x1)
    // As fraction: num = (x4-x1)*(x2-x1), den = (x2-x1)+(x4-x3)... 
    // actually x = x1 + (x4-x1)*(x2-x1) / ((x2-x1)+(x4-x3))
    
    // For same direction: a: (x1,0)->(x2,1), b: (x3,0)->(x4,1)
    // t = 1-s still doesn't apply; let's redo:
    // a: y=t, x = x1+t*(x2-x1)
    // b: y=s, x = x3+s*(x4-x3)  
    // Intersect: t=s and x1+t*(x2-x1)=x3+t*(x4-x3)
    // t*(x2-x1-x4+x3) = x3-x1
    // t = (x3-x1)/(x2-x1-x4+x3)  ... only if denominator != 0
    // If denom=0: parallel (no intersection unless overlapping, which is excluded)
    
    // This is getting complex. Let's use the general intersects() function above
    // and store intersection points as reduced fractions to deduplicate.
    
    // Actually, let me reconsider the problem:
    // "count how many times the two beams intersect"
    // From example 1: red has 5 bounces -> 6 segments, blue has 7 -> 8 segments
    // Answer is 7.
    // The shared start at (0,0) is counted. 
    // Multiple segments from one beam don't share internal points with multiple 
    // segments of other beam at same location (except possibly at reflection points).
    
    // The main concern: if beams meet at a reflection point, that point is shared
    // by two consecutive segments of one or both beams. We should count it once.
    
    // Approach: collect all intersection points as exact fractions, put in set, count unique.
    
    // Represent x-coordinate of intersection as pair<ll,ll> (reduced fraction).
    // Two intersections at same x and same y-level = same point.
    // Since y at intersection is determined by x within a segment, same x => same point.
    // (Assuming no two different intersection points have same x — possible but rare)
    // Actually same x could occur at different y if beams cross at different heights...
    // No: for a given x, each beam is at a unique y (it's a function).
    // So intersection point is unique per x value. Use x as key (as reduced fraction).
    
    // But wait: can two different pairs of segments intersect at the same x?
    // Yes! If beams meet at a reflection point on y=0, and that x happens to also
    // be where another pair of segments cross... but problem says no overlap,
    // so this seems unlikely in general but possible.
    // For correctness, store (x_num, x_den, y_num, y_den) reduced.
    
    // Given constraints N,M<=500, we have at most 500*500=250000 segment pairs.
    // Each intersection is a rational point. Store in set.
    
    set<tuple<ll,ll,ll,ll>> ipts;
    
    auto gcd = [](ll a, ll b) -> ll {
        a = abs(a); b = abs(b);
        while(b) { a%=b; swap(a,b); } return a?a:1;
    };
    
    auto reduce = [&](ll num, ll den) -> pair<ll,ll> {
        if (den < 0) { num = -num; den = -den; }
        ll g = gcd(abs(num), den);
        return {num/g, den/g};
    };
    
    for (auto& a : red) {
        for (auto& b : blue) {
            if (!intersects(a, b)) continue;
            // Find intersection point as exact fraction
            // General line intersection:
            // Line a: direction (a.x2-a.x1, a.y2-a.y1)
            // Line b: direction (b.x2-b.x1, b.y2-b.y1)
            // Using parametric form and solving:
            // P = A1 + t*(A2-A1)
            // Q = B1 + s*(B2-B1)
            // P = Q =>
            // t = cross(B2-B1, A1-B1) / cross(A2-A1, B2-B1)  ... wait let me be careful
            
            // cross(u,v) = ux*vy - uy*vx
            // t = cross((B2-B1), (B1-A1)) / cross((A2-A1), (B2-B1))
            
            ll ax = a.x2 - a.x1, ay = a.y2 - a.y1;
            ll bx = b.x2 - b.x1, by = b.y2 - b.y1;
            ll cx = b.x1 - a.x1, cy = b.y1 - a.y1;
            
            ll denom = ax * by - ay * bx; // cross(A2-A1, B2-B1)
            
            if (denom == 0) {
                // Parallel or collinear - problem says no overlap
                // Could share an endpoint; but intersects() returned true
                // meaning they share an endpoint
                // Find the shared endpoint(s)
                // Check all 4 endpoint combinations
                auto addPt = [&](ll x, ll y) {
                    ipts.insert({x, 1, y, 1});
                };
                if (a.x1 == b.x1 && a.y1 == b.y1) addPt(a.x1, a.y1);
                if (a.x1 == b.x2 && a.y1 == b.y2) addPt(a.x1, a.y1);
                if (a.x2 == b.x1 && a.y2 == b.y1) addPt(a.x2, a.y2);
                if (a.x2 == b.x2 && a.y2 == b.y2) addPt(a.x2, a.y2);
            } else {
                // t_num / denom
                ll t_num = cx * by - cy * bx;
                // Intersection: (a.x1 + t_num/denom * ax, a.y1 + t_num/denom * ay)
                // x = a.x1 + t_num * ax / denom = (a.x1 * denom + t_num * ax) / denom
                ll xnum = a.x1 * denom + t_num * ax;
                ll xden = denom;
                ll ynum = a.y1 * denom + t_num * ay;
                ll yden = denom;
                auto [xn, xd] = reduce(xnum, xden);
                auto [yn, yd] = reduce(ynum, yden);
                ipts.insert({xn, xd, yn, yd});
            }
        }
    }
    
    cout << ipts.size() << "\n";
    return 0;
}
