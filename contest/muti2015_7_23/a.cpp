#include <iostream>

int n;

void work_up_50()
{
    int index = 1, tot = 0;
    int r = (n - 48)/2;
    for (int i = 0; i < r; i++) {
        std::cout << index++ << " - ";
        std::cout << index++ << '\n';
        tot++;
    }
    if (n&1) {
        std::cout << index++ << " * " << n+1 << '\n';
        tot++;
    }
    for (int i = 0; i < 24; i++) {
        std::cout << index++ << " / ";
        std::cout << index++ << '\n';
        tot++;
    }

    if (n & 1) { index++; }

    for (int i = 0; i < n-1-tot; i++) {
        std::cout << index++ << " + ";
        std::cout << index++ << '\n';
    }
}

void work_up_20_even()
{
    int r = (n - 20) / 2, index = 1;
    for (int i = 0; i < 10; i++) {
        std::cout << index++ << " / ";
        std::cout << index++ << "\n";
    }

    std::cout << n+1 << " + " << n+2 << "\n";
    std::cout << n+3 << " + " << n+4 << "\n";
    std::cout << n+11 << " + " << n+12 << "\n";
//n+13 -> 4

    std::cout << n+5 << " + " << n+6 << "\n";
    std::cout << n+7 << " + " << n+8 << "\n";
    std::cout << n+9 << " + " << n+10 << "\n";
    std::cout << n+14 << " + " << n+15 << "\n";
    std::cout << n+16 << " + " << n+17 << "\n";
//n+18 -> 6
    std::cout << n+13 << " * " << n + 18 << "\n";

    for (int i = 0; i < r; i++) {
        std::cout << index++ << " - ";
        std::cout << index++ << "\n";
    }

    index = n + 19;
    for (; index < 2*n-2; ) {
        std::cout << index++ << " + ";
        std::cout << index++ << "\n";
    }
}

void work_up_20_odd()
{
    if (n < 24) {
        int p = 24 - n, r = (n-1-2*p)/2, index = 1;
        for (int i = 0; i < p; i++) {
            std::cout << index++ << " / ";
            std::cout << index++ << "\n";
        }
        int t2 = n+1;
        for (int i = 0; i < p-1; i++) {
            std::cout << t2++ << " + ";
            std::cout << t2++ << "\n";
        }

        std::cout << index++ << " + ";
        std::cout << t2++ << "\n";

        for (int i = 0; i < r; i++) {
            std::cout << index++ << " - ";
            std::cout << index++ << "\n";
        }

        if (n == 18) {
            std::cout << "18 * 31\n32 + 30\n33 + 34\n";
            return;
        }

        for (; t2 < 2*n-2; ) {
            std::cout << t2++ << " + ";
            std::cout << t2++ << "\n";
        }

        return;
    }

    int p = n - 24, r = (n-1-2*p)/2, index = 1;
    for (int i = 0; i < p; i++) {
        std::cout << index++ << " / ";
        std::cout << index++ << "\n";
    }
    int t2 = n+1;
    for (int i = 0; i < p-1; i++) {
        std::cout << t2++ << " + ";
        std::cout << t2++ << "\n";
    }

    std::cout << index++ << " - ";
    std::cout << t2++ << "\n";

    for (int i = 0; i < r; i++) {
        std::cout << index++ << " - ";
        std::cout << index++ << "\n";
    }

    for (; t2 < 2*n-2; ) {
        std::cout << t2++ << " + ";
        std::cout << t2++ << "\n";
    }
}

int main()
{
    while (std::cin >> n) {
        if (n == 1 || n == 2 || n == 3 || n == 5) {
            std::cout << "-1\n";
            continue;
        }
        if (n == 4) {
            std::cout << "1 * 2\n5 + 3\n6 + 4\n";
            continue;
        }
        if (n == 49) {
            std::cout << "1 / 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 / 12\n13 / 14\n15 / 16\n17 / 18\n19 / 20\n50 + 51\n52 + 53\n60 + 61\n54 + 55\n56 + 57\n58 + 59\n63 + 64\n65 + 66\n62 * 67\n21 - 22\n23 - 24\n25 - 26\n27 - 28\n29 - 30\n31 - 32\n33 - 34\n35 - 36\n37 - 38\n39 - 40\n41 - 42\n43 - 44\n45 - 46\n47 - 48\n68 + 69\n70 + 71\n72 + 73\n74 + 75\n76 + 77\n78 + 79\n80 + 81\n82 + 83\n84 + 85\n86 + 87\n88 + 89\n91 * 49\n90 + 92\n93 + 94\n95 + 96\n";
        } else
        if (n >= 50) {
            work_up_50();
        } else
        if ((n >= 20 && !(n & 1)) || n == 49) {
            work_up_20_even();
        } else
        if ((n >= 17 && (n & 1)) || n == 18) {
            work_up_20_odd();
        } else
        if (n == 16) {
            std::cout <<"1 / 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 / 12\n17 + 18\n19 + 20\n21 + 22\n24 + 25\n13 - 26\n27 * 26\n14 - 15\n16 * 29\n28 + 30\n";
        } else
        if (n == 15) {
            std::cout << "1 / 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n16 + 17\n18 + 21\n19 + 20\n11 - 22\n24 * 23\n13 - 12\n15 - 14\n25 + 26\n27 + 28\n";
        } else
        if (n == 14) {
            std::cout << "1 / 2\n3 / 4\n5 / 6\n7 / 8\n15 + 16\n17 + 18\n19 + 20\n9 + 10\n22 - 21\n12 - 11\n14 - 13\n23 + 24\n25 + 26\n";
        } else
        if (n == 13) {
            std::cout << "1 + 2\n3 / 4\n5 / 6\n7 - 8\n9 + 10\n11 + 18\n12 + 19\n13 + 20\n17 * 21\n14 - 15\n23 - 16\n22 + 24\n";
        } else
        if (n == 12) {
            std::cout << "1 + 2\n3 - 4\n5 + 6\n7 + 15\n8 + 16\n9 + 17\n10 + 18\n11 + 19\n12 + 20\n14 * 21\n13 + 22\n";
        } else
        if (n == 11) {
            std::cout << "1 + 2\n3 / 4\n5 / 6\n7 - 8\n9 + 10\n11 + 16\n15 * 17\n12 + 13\n14 + 19\n18 + 20\n";
        } else
        if (n == 10) {
            std::cout << "1 + 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 + 12\n13 + 16\n14 + 17\n15 + 18\n";
        } else
        if (n == 9) {
            std::cout << "1 + 2\n3 + 10\n4 / 5\n6 / 7\n8 / 9\n12 + 13\n14 + 15\n11 - 16\n";
        } else
        if (n == 8) {
            std::cout << "1 + 2\n3 + 9\n4 - 5\n6 + 7\n8 + 12\n11 * 13\n10 + 14\n";
        } else
        if (n == 7) {
            std::cout << "1 * 2\n3 / 4\n8 - 9\n5 * 10\n6 + 7\n11 / 12\n";
        } else
        if (n == 6) {
            std::cout << "1 / 2\n3 / 4\n7 + 8\n5 - 9\n6 * 10\n";
        }
    }
}
