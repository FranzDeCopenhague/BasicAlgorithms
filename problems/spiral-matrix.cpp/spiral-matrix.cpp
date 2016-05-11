/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 

*/

class Solution {
public:
    enum class Direction {RIGHT, BOTTOM, LEFT, TOP};

     vector<int> spiralOrder(vector<vector<int> >& matrix)
     {
         vector<int> output;
         

         int m = matrix.empty() ? 0 : matrix[0].size();
         int n = matrix.size();
         size_t count = m * n;

         int L(0), T(0), R(m - 1), B(n - 1), x(0), y(0);

         auto direction = Direction::RIGHT;
         while (output.size() < count) {
             switch (direction) {
             case Direction::RIGHT:
                 for (; x <= R; ++x) { output.push_back(matrix[y][x]); }
                 x = R;
                 y = ++T;
                 direction = Direction::BOTTOM;
                 break;
             case Direction::BOTTOM:
                 for (; y <= B; ++y) { output.push_back(matrix[y][x]); }
                 y = B;
                 x = --R;
                 direction = Direction::LEFT;
                 break;
             case Direction::LEFT:
                 for (; x >= L; --x) { output.push_back(matrix[y][x]); }
                 x = L;
                 y = --B;
                 direction = Direction::TOP;
                 break;
             case Direction::TOP:
                 for (; y >= T; --y) { output.push_back(matrix[y][x]); }
                 y = T;
                 x = ++L;
                 direction = Direction::RIGHT;
                 break;
             }
         }


         return output;
     }

};
