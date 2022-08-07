#include <iostream>
#include <algorithm>
#include <string>
#ifndef __USE_VECTOR__
#include <queue>
#endif
#include <vector>
#include <cmath>

using namespace std;

struct Points {
  int x;
  int y;
  Points(): x(0), y(0) {}
  Points(int x, int y): x(x), y(y) {}
};

// Question: Given an array of points, calculate the area of the rectangle formed by those points

string ArrayChallenge(string strArr[], int arrLength) {
  
  // code goes here
#ifndef __USE_VECTOR__
  struct cmp {
    bool operator() (const Points& a, const Points& b) {
      if (a.x == b.x)
        return a.y > b.y;
      return a.x > b.x;
    }
  };
  priority_queue<Points, vector<Points>, cmp> ps;
#endif
  vector<Points> v;

  for (size_t i = 0; i < arrLength; i++) {
    size_t d = strArr[i].find(' ');
    int x = stoi(strArr[i].substr(1, d-1));
    int y = stoi(strArr[i].substr(d+1));
    Points p(x, y);
#ifdef __USE_VECTOR__
    v.push_back(p);
#else
    ps.push(p);
#endif
  }


  // sort the points so that they are in order
#ifdef __USE_VECTOR__
  sort(v.begin(), v.end(), [](const Points& a, const Points& b) { if (a.x == b.x) return a.y < b.y; return a.x < b.x;});
#else
  while (!ps.empty()) {
    v.push_back(ps.top());
    ps.pop();
  }
#endif
 
  // Distance formula to calculate length and width
  // length = sqrt ((x4 - x1)^2 + (y4 - y1)^2)
  // width = sqrt ((x4 - x3)^2 + (y4 - y3)^2)
  // area = length * width 
  int lx1 = v[0].x - v[1].x;
  int ly1 = v[0].y - v[1].y;
  int lx2 = v[0].x - v[2].x;
  int ly2 = v[0].y - v[2].y;

  double s1 = sqrt((lx1 * lx1) + (ly1 * ly1));
  double s2 = sqrt((lx2 * lx2) + (ly2 * ly2));
  cout << s1 << endl;
  cout << s2 << endl;

  strArr[0] = to_string(s1 * s2);
  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = {"(1 1)","(1 3)","(3 1)","(3 3)"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayChallenge(A, arrLength) << endl;
  string B[] = {"(1 1)","(0 2)","(3 3)","(2 4)"};
  arrLength = sizeof(B) / sizeof(*B);
  cout << ArrayChallenge(B, arrLength) << endl;
  return 0;
    
}
