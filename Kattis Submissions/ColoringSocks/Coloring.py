s, c, k = map(int, input().split())
colors = list(map(int, input().split()))

colors.sort()

machines = 0
current_load = 0
current_color = colors[0]

for color in colors:
    if abs(color - current_color) <= k and current_load < c:
        current_load += 1
        
    else:
        machines += 1
        current_load = 1
        current_color = color

if current_load > 0:
    machines += 1

print(machines)