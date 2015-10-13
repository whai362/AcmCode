int MR(char *s, int len) {
    int i = 0, j = 1, cnt = 0;
    while (i < len && j < len && cnt < len) {
        if(s[(i + cnt) % len] == s[(j + cnt) % len])
            cnt++;
        else {
            if (s[(i + cnt) % len] > s[(j + cnt) % len]) 
                 i = i + cnt + 1;
            else
                 j = j + cnt + 1;
            if (i == j) ++j;
            cnt = 0;
        }
    }
    return min(i,j);
}
