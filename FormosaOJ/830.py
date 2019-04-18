import math

def det(a11, a12, a13, a21, a22, a23, a31, a32, a33):
    return a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a13*a22*a31 - a12*a21*a33 - a11*a23*a32
def dis(x1, y1, x2, y2):
    return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

while True:
    try:
        s = raw_input();
    t = s.split(' ')
    x1 = int(t[0])
    y1 = int(t[1])
    x2 = int(t[2])
    y2 = int(t[3])
    x3 = int(t[4])
    y3 = int(t[5])
    a = dis(x1, y1, x2, y2)
    b = dis(x2, y2, x3, y3)
    c = dis(x3, y3, x1, y1)

    isAns = False
    
    if max(a, b, c) == a:
        x = (x1 + x2) / 2
        y = (y1 + y2) / 2
        r = a / 2
        if dis(x, y, x3, y3) <= r:
            isAns = True
    elif max(a, b, c) == b:
        x = (x2 + x3) / 2
        y = (y2 + y3) / 2
        r = b / 2
        if dis(x, y, x1, y1) <= r:
            isAns = True
    else:
        x = (x3 + x1) / 2
        y = (y3 + y1) / 2
        r = c / 2
        if dis(x, y, x2, y2) <= r:
            isAns = True

    if isAns == False:
        x = det(x1**2 + y1**2, y1, 1, x2**2 + y2**2, y2, 1, x3**2 + y3**2, y3, 1) / 2 / det(x1, y1, 1, x2, y2, 1, x3, y3, 1)
        y = det(x1, x1**2 + y1**2, 1, x2, x2**2 + y2**2, 1, x3, x3**2 + y3**2, 1) / 2 / det(x1, y1, 1, x2, y2, 1, x3, y3, 1)
        r = dis(x1, y1, x, y)
    print(x,y,r)
