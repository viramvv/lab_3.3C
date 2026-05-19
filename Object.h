#pragma once

class Object {
private:
    static int count;
public:
    Object();
    Object(const Object& other);
    virtual ~Object();

    static int GetCount();
};