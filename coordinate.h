#ifndef COORDINATE_H
#define COORDINATE_H

typedef struct
{
  float x;
  float y;
  int coord_id;
  struct _coordinate *next;
  struct _coordinate *previous;
}Coordinate;

#endif
