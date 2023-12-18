package com.zyp;

import com.zyp.ICallback;

interface IHello
{
    void hello();
    int sum(int x, int y);
    void registerCallback(ICallback cb);
}