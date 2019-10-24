#ifndef OBJECT_H
#define OBJECT_H

class RenderComponent;

class Object {

public:
    Object(std::unique_ptr<RenderComponent> renderComponent): _renderCompoennt(renderComponent) {}
    std::unique_ptr<Mesh>& getMesh() {return _m;} 

private:
    std::unique_ptr<RenderComponent> __renderComponent;
};

#endif