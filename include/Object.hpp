#ifndef OBJECT_H
#define OBJECT_H

class Object {

public:
    Object(std::unique_ptr<Mesh> m): _m(m) {}
    std::unique_ptr<Mesh>& getMesh() {return _m;} 

private:
    std::unique_ptr<Mesh> _m;
};

#endif