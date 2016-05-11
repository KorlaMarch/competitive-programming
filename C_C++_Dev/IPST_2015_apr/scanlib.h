#ifndef SCANLIB_H_INCLUDED
#define SCANLIB_H_INCLUDED

int scan_init();
int detect(int r1, int c1, int r2, int c2);
void scan_report(int k, int items[][4]);

#endif
