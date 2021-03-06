/*
 * Copyright 2017 Milian Wolff <mail@milianw.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdlib.h>

char* allocate_something(int size)
{
    return malloc(size);
}

char* foo()
{
    return allocate_something(100);
}

char* bar()
{
    return allocate_something(25);
}

int main()
{
    char* f1 = foo();
    char* b2 = bar();
    free(f1);
    char* b3 = bar();
    char* b4 = bar();
    free(b2);
    free(b3);
    free(b4);
    char* f2 = foo();
    free(f2);
    return 0;
}
