
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool isConvexPolygon(Point p1, Point p2, Point p3, Point p4) {
    int crossProduct1 = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    int crossProduct2 = (p3.x - p2.x) * (p4.y - p3.y) - (p4.x - p3.x) * (p3.y - p2.y);
    int crossProduct3 = (p4.x - p3.x) * (p1.y - p4.y) - (p1.x - p4.x) * (p4.y - p3.y);
    int crossProduct4 = (p1.x - p4.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p1.y - p4.y);
    if ((crossProduct1 >= 0 && crossProduct2 >= 0 && crossProduct3 >= 0 && crossProduct4 >= 0) ||
        (crossProduct1 <= 0 && crossProduct2 <= 0 && crossProduct3 <= 0 && crossProduct4 <= 0)) {
        return true;
    }
    return false;
}

int main() {
    Point p1,p2,p3,p4;
      cin>>p1.x>>p1.y;
      cin>>p2.x>>p2.y;
      cin>>p3.x>>p3.y;
      cin>>p4.x>>p4.y;
    if (isConvexPolygon(p1, p2, p3, p4)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}


/*
凸多边形的性质之一是，任意一条边上的点与其他点构成的向量的叉积具有相同的符号（非零）。如果给定的四个点构成凸多边形，那么对于每条边，另外两个点分别位于该边的两侧，因此它们构成的向量的叉积应该具有相同的符号。

具体来说，我们可以将四个点依次标记为 p1、p2、p3 和 p4。我们需要计算以下四个叉积：

叉积 crossProduct1：(p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y)
叉积 crossProduct2：(p3.x - p2.x) * (p4.y - p3.y) - (p4.x - p3.x) * (p3.y - p2.y)
叉积 crossProduct3：(p4.x - p3.x) * (p1.y - p4.y) - (p1.x - p4.x) * (p4.y - p3.y)
叉积 crossProduct4：(p1.x - p4.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p1.y - p4.y)
如果所有的叉积都具有相同的符号（非零），那么给定的四个点构成凸多边形。这是因为所有的向量叉积都具有相同的符号意味着每条边上的另外两个点都在该边的同一侧，符合凸多边形的定义。

如果至少有一个叉积为零或者叉积具有不同的符号，那么给定的四个点不构成凸多边形。

因此，通过计算这四个叉积并检查它们的符号，我们可以判断给定的四个点是否构成凸多边形。
*/