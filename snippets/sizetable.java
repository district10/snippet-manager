final static int [] sizeTable = {
        9, 99, 999, 9999, 99999,
        999999, 9999999, 99999999,
        999999999, Integer.MAX_VALUE
};
// Requires positive x
static int stringSize(int x) {
    for (int i=0; ; i++)
        if (x <= sizeTable[i])
            return i+1;
}
