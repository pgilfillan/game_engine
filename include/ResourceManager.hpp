#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResouceManager {

public:
    Object(std::unique_ptr<Mesh> m): _m(m) {}
    std::unique_ptr<Mesh>& getMesh() {return _m} 

private:
    std::unique_ptr<Mesh> _m;
}

#endif