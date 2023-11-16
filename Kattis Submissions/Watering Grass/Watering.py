import math

EPS = 1e-9

def comparator(sprinkler):
    return sprinkler[0], -sprinkler[1]

while True:
    try:
        n, l, w = map(int, input().split())
        circles = []
        for _ in range(n):
            position, radius = map(int, input().split())

            if radius >= w/2:
                water_range = math.sqrt(radius**2 - (w / 2.0)**2)
                left = position - water_range
                right = position + water_range
                circles.append((left, right))

            else:
                circles.append((position, position))

        circles.sort(key=comparator)

        possible = True
        covered = 0.0
        count = 0
        skip = 0

        for i in range(n):
            if not possible:
                break

            if covered > l:
                break

            if i < skip:
                continue

            if circles[i][1] < covered + EPS:
                continue

            if circles[i][0] < covered + EPS:
                max_r = -1.0
                skip = i
                for j in range(i, n):
                    if not (circles[j][0] < covered+EPS):
                        break
                    if circles[j][1] > max_r:
                        max_r = circles[j][1]
                        skip = j
                count += 1
                covered = max_r
            else:
                possible = False

        if not possible or covered < l:
            print(-1)
        else:
            print(count)

    except:
        break
