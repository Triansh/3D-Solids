#include <bits/stdc++.h>
using namespace std;

signed main()
{

    int VERTICES = 11;
    float ANGLE = 2.0 * acos(-1) / 11;

    float vertices[VERTICES * 3 + 6];
    float RADIUS = 2.50;

    for (int i = 0; i < VERTICES; i++)
    {
        int a = 3 * i;
        vertices[a + 0] = RADIUS * cos(i * ANGLE);
        vertices[a + 1] = RADIUS * sin(i * ANGLE);
        vertices[a + 2] = RADIUS * 0;
        cout << setprecision(6) << vertices[a] << ", " << vertices[a + 1] << ", " << vertices[a + 2] << "\n";
        // sumx += vertices[a];
        // sumy += vertices[a + 1];
    }
    vertices[VERTICES * 3] = vertices[VERTICES * 3 + 1] = 0;
    vertices[VERTICES * 3 + 2] = RADIUS;
    vertices[VERTICES * 3 + 3] = vertices[VERTICES * 3 + 4] = vertices[VERTICES * 3 + 5] = 0;
    // vertices[23] = -RADIUS;
    // vertices[18] = vertices[19] = vertices[21] = vertices[22] = 0;

    cout << setprecision(6) << 0.0 << ", " << 0.0 << ", " << RADIUS << "\n";
    // cout << setprecision(6) << 0.0 << ", " << 0.0 << ", " << -RADIUS << "\n";

    cout << "******************************************************\n";
    int NF = 11; // no of faces
    int TF = 1;  // no of triangles for each face

    unsigned int indexes[][3] = {
            {0, 1, 11},
            {1, 2, 11},
            {2, 3, 11},
            {3, 4, 11},
            {4, 5, 11},
            {5, 6, 11},
            {6, 7, 11},
            {7, 8, 11},
            {8, 9, 11},
            {9, 10, 11},
            {10, 0, 11},

            {0, 1, 12},
            {1, 2, 12},
            {2, 3, 12},
            {3, 4, 12},
            {4, 5, 12},
            {5, 6, 12},
            {6, 7, 12},
            {7, 8, 12},
            {8, 9, 12},
            {9, 10, 12},
            {10, 0, 12},

            // {0, 1, 6},
            // {1, 2, 6},
            // {2, 3, 6},
            // {3, 4, 6},
            // {4, 5, 6},
            // {5, 0, 6},

    };

    cout << "VERTICES:"
         << "\n";

    for (int i = 0; i < 2 * NF; i++)
    {
        for (int j = 0; j < 3 * TF; j++)
        {
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
            {.25, .5, .75},
            {.5, .25, .5},
            {.5, .75, .25},
            {.75, .75, .75},
            {.25, .5, .25},
            {.5, .5, .75},
            {.5, .75, .5},
            {.75, .5, .5},
            {.25, .75, .5},
            {.75, .25, .5},
            {.5, .25, .75},
    };

    cout << "COLORS:"
         << "\n";
    for (int i = 0, j = 0; i < VERTICES; i++, j = (j + 1) % TC)
    {
        for (int k = 0; k < 3 * TF; k++)
        {
            for (int l = 0; l < CP; l++)
                cout << colors[j][l] << ", ";
            cout << "\n";
        }
        cout << "\n";
    }

    for (int i = 0, j = 0; i < VERTICES; i++, j = (j + 1) % TC)
    {
        for (int k = 0; k < 3 * TF; k++)
        {
            for (int l = 0; l < CP; l++)
                cout << colors[11][l] << ", ";
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}