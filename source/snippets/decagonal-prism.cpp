#include <bits/stdc++.h>
using namespace std;

signed main() {

    int VERTICES = 20;
    float ANGLE = 2.0 * acos(-1) / 10;

    float vertices[VERTICES * 3 + 6];
    float RADIUS = 2.00;

    for (int i = 0; i < VERTICES; i++) {
        int a = 3 * i;
        vertices[a + 0] = RADIUS * cos(i * ANGLE);
        vertices[a + 1] = RADIUS * sin(i * ANGLE);
        vertices[a + 2] = RADIUS / 2.0 * ((i >= VERTICES / 2) ? -1 : 1);
        // cout << setprecision(6) << vertices[a] << ", " << vertices[a + 1] << ", " << vertices[a + 2] << "\n";
        // sumx += vertices[a];
        // sumy += vertices[a + 1];
    }
    vertices[VERTICES * 3] = vertices[VERTICES * 3 + 1] = 0;
    vertices[VERTICES * 3 + 2] = RADIUS / 2;
    vertices[VERTICES * 3 + 3] = vertices[VERTICES * 3 + 4] = 0;
    vertices[VERTICES * 3 + 5] = -RADIUS / 2;
    // vertices[23] = -RADIUS;
    // vertices[18] = vertices[19] = vertices[21] = vertices[22] = 0;

    cout << setprecision(6) << 0.0 << ", " << 0.0 << ", " << RADIUS << "\n";
    // cout << setprecision(6) << 0.0 << ", " << 0.0 << ", " << -RADIUS << "\n";

    cout << "******************************************************\n";
    int NF = 40; // no of faces
    int TF = 1;  // no of triangles for each face

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "{" << i << ", " << i + 1 << ", " << i + 11 << "},\n";
    //     cout << "{" << i + 10 << ", " << i + 11 << ", " << i << "},\n";
    //     cout << "\n";
    // }

    unsigned int indexes[][3] = {
            {0,  1,  11},
            {10, 11, 0},

            {1,  2,  12},
            {11, 12, 1},

            {2,  3,  13},
            {12, 13, 2},

            {3,  4,  14},
            {13, 14, 3},

            {4,  5,  15},
            {14, 15, 4},

            {5,  6,  16},
            {15, 16, 5},

            {6,  7,  17},
            {16, 17, 6},

            {7,  8,  18},
            {17, 18, 7},

            {8,  9,  19},
            {18, 19, 8},

            {9,  0,  10},
            {19, 10, 9},

            {0,  1,  20},
            {1,  2,  20},
            {2,  3,  20},
            {3,  4,  20},
            {4,  5,  20},
            {5,  6,  20},
            {6,  7,  20},
            {7,  8,  20},
            {8,  9,  20},
            {9,  0,  20},

            {10, 11, 21},
            {11, 12, 21},
            {12, 13, 21},
            {13, 14, 21},
            {14, 15, 21},
            {15, 16, 21},
            {16, 17, 21},
            {17, 18, 21},
            {18, 19, 21},
            {19, 10, 21},

            // {0, 1, 6},
            // {1, 2, 6},
            // {2, 3, 6},
            // {3, 4, 6},
            // {4, 5, 6},
            // {5, 0, 6},

    };

    cout << "VERTICES:"
         << "\n";

    for (int i = 0; i < NF; i++) {
        for (int j = 0; j < 3 * TF; j++) {
            for (int k = 0; k < 3; k++)
                cout << setprecision(6) << vertices[3 * indexes[i][j] + k] << ", ";

            cout << "\n";
        }
        cout << "\n";
    }

    int CP = 3;  // colr params
    int TC = 12; // total colors

    float colors[][3] = {
            {.25, .25, .5},
            {.25, .5,  .75},
            {.5,  .25, .5},
            {.5,  .75, .25},
            {.75, .75, .75},
            {.25, .5,  .25},
            {.5,  .5,  .75},
            {.5,  .75, .5},
            {.75, .5,  .5},
            {.25, .75, .5},
            {.75, .25, .5},
            {.5,  .25, .75},
    };

    cout << "COLORS:"
         << "\n";
    for (int i = 0, j = 0; i < VERTICES; ++i, j = i % 2 == 0 ? ((j + 1) % TC) : j) {
        for (int k = 0; k < 3 * TF; k++) {
            for (int l = 0; l < CP; l++)
                cout << colors[j][l] << ", ";
            cout << "\n";
        }
        cout << "\n";
    }

    for (int i = 0, j = 0; i < VERTICES / 2; i++, j = (j + 1) % TC) {
        for (int k = 0; k < 3 * TF; k++) {
            for (int l = 0; l < CP; l++)
                cout << colors[10][l] << ", ";
            cout << "\n";
        }
        cout << "\n";
    }

    for (int i = 0, j = 0; i < VERTICES / 2; i++, j = (j + 1) % TC) {
        for (int k = 0; k < 3 * TF; k++) {
            for (int l = 0; l < CP; l++)
                cout << colors[11][l] << ", ";
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}