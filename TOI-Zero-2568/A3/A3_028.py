# รับขนาดของตาราง
n, m = map(int, input().split())

# รับจำนวนระเบิด
b = int(input())

# สร้างตารางเปล่า (ค่าเริ่มต้นเป็น 0)
grid = [[0 for _ in range(m)] for _ in range(n)]

# รับตำแหน่งระเบิด
bombs = []
for _ in range(b):
    r, c = map(int, input().split())
    bombs.append((r, c))
    grid[r][c] = 'x'  # ใส่ระเบิดลงในตาราง

# 8 ทิศทางรอบๆ จุด (dx, dy)
directions = [(-1, -1), (-1, 0), (-1, 1),
              (0, -1),          (0, 1),
              (1, -1),  (1, 0),  (1, 1)]

# นับจำนวนระเบิดรอบๆ เฉพาะช่องที่ไม่ใช่ระเบิด
for r, c in bombs:
    for dr, dc in directions:
        nr, nc = r + dr, c + dc
        if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] != 'x':
            grid[nr][nc] += 1

# แสดงผลลัพธ์
for row in grid:
    print(' '.join(str(cell) for cell in row))
