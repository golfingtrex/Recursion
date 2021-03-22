#include<stdio.h>

#define DISKS   3

void Move( int count, int start, int finish, int temp );

int main( void ) {
    Move( DISKS, 1, 3, 2 );
    return 0;
}

void Move( int count, int start, int finish, int temp ) {
    if( count>0 ) {
        Move( count-1, start, temp, finish );
        printf( "Move a disk from %d to %d.\n", start, finish );
        Move( count-1, temp, finish, start );
    }
}
