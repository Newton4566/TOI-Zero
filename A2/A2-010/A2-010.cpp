#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// โครงสร้างข้อมูลสำหรับเก็บช่วงความลึกแต่ละเซกเมนต์
struct Segment {
    int depth;
    long long width;
};

int main() {
    // เพิ่มประสิทธิภาพการทำงานของ I/O ใน C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<Segment> segments;
    int current_depth = 0;
    int max_depth_reached = 0;

    // 1. อ่านข้อมูลหน้าตัดแม่น้ำและจำลองโครงสร้างความลึก
    for (int i = 0; i < N; ++i) {
        int d;
        long long l;
        cin >> d >> l;

        if (d == 1) {
            // เมื่อลึกขึ้น ระดับความลึกปัจจุบันจะถูกใช้ในช่วงความยาว l นี้
            current_depth += 1;
            segments.push_back({current_depth, l});
            max_depth_reached = max(max_depth_reached, current_depth);
        } else if (d == -1) {
            // เมื่อตื้นลง ระดับความลึกก่อนหน้านี้จะหายไป ความยาว l นี้จะอยู่ที่ระดับต่ำลงมา
            segments.push_back({current_depth, l});
            current_depth -= 1;
        }
    }

    // 2. หาความยาวรวมที่ต่อเนื่องกันของแต่ละระดับความลึก
    // max_width[h] จะเก็บความยาวต่อเนื่องสูงสุดที่มีความลึกอย่างน้อย h
    vector<long long> max_width(max_depth_reached + 2, 0);
    
    int i = 0;
    int num_segments = segments.size();
    
    while (i < num_segments) {
        int h = segments[i].depth;
        long long current_continuous_width = 0;
        
        // รวมเซกเมนต์ที่ต่อเนื่องกันทั้งหมดที่มีความลึก >= h
        int j = i;
        long long local_width = 0;
        
        while (j < num_segments) {
            if (segments[j].depth >= h) {
                local_width += segments[j].width;
                j++;
            } else {
                // เจอจุดที่ตื้นกว่า h ให้บันทึกความกว้างสูงสุดไว้ แล้วเคลียร์ค่าเพื่อเริ่มนับใหม่หากมีช่วงอื่นอีก
                max_width[h] = max(max_width[h], local_width);
                local_width = 0;
                // ข้ามไปยังเซกเมนต์ถัดไปที่อาจจะลึก >= h อีกครั้ง
                while (j < num_segments && segments[j].depth < h) {
                    j++;
                }
            }
        }
        max_width[h] = max(max_width[h], local_width);
        
        // ขยับไปพิจารณาที่ระดับความลึกถัดไป
        i++;
    }

    // 3. ทำ Suffix Maximum เนื่องจาก ถ้าความลึกที่มากกว่ารองรับความกว้าง L ได้ ความลึกที่น้อยกว่าย่อมรองรับได้เช่นกัน
    for (int h = max_depth_reached; h >= 1; --h) {
        max_width[h] = max(max_width[h], max_width[h + 1]);
    }

    // 4. ประมวลผลแต่ละคำถาม (Queries) ด้วย Binary Search
    for (int q = 0; q < Q; ++q) {
        long long boat_width;
        cin >> boat_width;

        // ค้นหาความลึกสูงสุด h ที่ max_width[h] >= boat_width
        int low = 1, high = max_depth_reached, ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (max_width[mid] >= boat_width) {
                ans = mid;       // เก็บคำตอบที่เป็นไปได้ไว้ก่อน
                low = mid + 1;   // ลองหาความลึกที่มากกว่าเดิม
            } else {
                high = mid - 1;  // ความลึกนี้แคบไป ต้องลดระดับความลึกขยับขึ้นมา
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}