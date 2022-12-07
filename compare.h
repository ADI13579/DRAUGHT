#pragma once
#include<iostream>
namespace {
    namespace comp
    {
        bool compare(int a, int b)
        {
            if (a >= 0 && a <= 7)
                if (b >= 0 && b <= 7)
                    return true;

            return false;
        }
        bool compare(int a, int b, int c, int d)
        {
            if (a >= 0 && a <= 7)
                if (b >= 0 && b <= 7)
                    if (c >= 0 && c <= 7)
                        if (d >= 0 && d <= 7)
                            return true;

            return false;
        }

        bool compare(int c)
        {
            if (c >= 0 && c <= 7)
                return true;

            return false;
        }
    }
};