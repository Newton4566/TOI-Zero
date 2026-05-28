#pragma GCC optimize("O3")
#include <iostream>
#include <vector>

using namespace std;

// ตารางเก็บผลการแข่งขันล่วงหน้า (เผื่อขนาดสูงสุด N = 32 + 1)
int match_table[35][35];

int main() {
    // เพิ่มความเร็วในการ Input/Output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    if (!(cin >> N >> C)) return 0;

    // อ่านข้อมูลตารางประเมินความสามารถ
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> match_table[i][j];
        }
    }

    // สร้างลิสต์ของทีมที่เข้าร่วมแข่งขันในรอบแรก (หมายเลข 1 ถึง N)
    vector<int> current_round_teams;
    for (int i = 1; i <= N; ++i) {
        current_round_teams.push_back(i);
    }

    // ตัวแปรเช็กสถานะบัตรพิเศษ: ถ้า C != 0 แสดงว่ามีบัตรพิเศษพร้อมใช้งาน
    bool has_card = (C != 0);

    // จำลองการแข่งขันไปเรื่อย ๆ จนกว่าจะเหลือผู้ชนะเพียงทีมเดียว
    while (current_round_teams.size() > 1) {
        vector<int> next_round_teams;

        // จับคู่แข่งกันทีละคู่ (ทีมที่ i กับ i+1)
        for (size_t i = 0; i < current_round_teams.size(); i += 2) {
            int team_a = current_round_teams[i];
            int team_b = current_round_teams[i + 1];

            // หาผู้ชนะตามปกติจากตารางประเมินผล
            int normal_winner = match_table[team_a][team_b];
            int normal_loser = (normal_winner == team_a) ? team_b : team_a;

            // ตรวจสอบเงื่อนไขการใช้บัตรพิเศษ
            // ทีมที่แพ้ตามปกติคือทีม C และทีม C ยังไม่เคยใช้บัตรพิเศษ
            if (normal_loser == C && has_card) {
                // ทีม C ใช้บัตรพิเศษ ทำให้พลิกกลับมาชนะและผ่านเข้ารอบ
                next_round_teams.push_back(C);
                has_card = false; // บัตรพิเศษถูกใช้ไปแล้ว
            } else {
                // กรณีปกติ ไม่มีใครใช้บัตร ผู้ชนะตามตารางจะได้เข้ารอบ
                next_round_teams.push_back(normal_winner);
            }
        }

        // อัปเดตทีมสำหรับแข่งขันในรอบถัดไป
        current_round_teams = next_round_teams;
    }

    // แสดงหมายเลขทีมที่ชนะเลิศการแข่งขัน
    cout << current_round_teams[0] << "\n";

    return 0;
}