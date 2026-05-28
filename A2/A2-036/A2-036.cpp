#include <iostream>
#include <vector>

using namespace std;

int main() {
    // เพิ่มความเร็วในการรับ-ส่งข้อมูล
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, query_count;
    if (!(cin >> num >> query_count)) return 0;

    // สร้างอาร์เรย์สำหรับบันทึกการเปลี่ยนแปลง (Difference Array) 
    // ขนาด 1442 ครอบคลุมช่วงนาที 0 ถึง 1440
    int diff[1445] = {0};

    // รับค่าเวลาเปิด-ปิดของแต่ละร้าน
    for (int i = 0; i < num; ++i) {
        int start, stop;
        cin >> start >> stop;
        
        // บันทึกจุดที่มีการเปลี่ยนแปลง
        // เปิดร้าน: จำนวนร้านที่เปิดอยู่เพิ่มขึ้น 1
        // ปิดร้าน: จำนวนร้านที่เปิดอยู่ลดลง 1
        if (start < 1445) diff[start]++;
        if (stop < 1445) diff[stop]--;
    }

    // สร้าง Timeline โดยใช้ Prefix Sum เพื่อสรุปจำนวนร้านที่เปิดในแต่ละนาที
    int timeline[1445] = {0};
    int current_open = 0;
    for (int i = 0; i <= 1440; ++i) {
        current_open += diff[i];
        timeline[i] = current_open;
    }

    // รับค่าเวลาที่ต้องการตรวจสอบ (Queries) และแสดงผลลัพธ์ทันที
    for (int i = 0; i < query_count; ++i) {
        int q_time;
        cin >> q_time;
        
        // ป้องกันกรณี query นอกช่วงที่กำหนด (ถ้ามี)
        if (q_time >= 0 && q_time <= 1440) {
            cout << timeline[q_time];
        } else {
            cout << 0;
        }

        // เว้นวรรคระหว่างคำตอบ (ยกเว้นตัวสุดท้าย)
        if (i < query_count - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}