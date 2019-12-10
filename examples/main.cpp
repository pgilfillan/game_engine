int main() {
    Application a;
    Scene initialScene = getInitialScene(); // game specific
    Scene otherScene = getOtherScene(); // game specific
    int index = a.addScene(initialScene, "Initial Scene")
    index = a.addScene(initialScene, "Other Scene")

    a.setCurrentScene("Initial Scene"); // can default to first added

    while (!a.finished()) {
        updateScene();
        drawScene();
    }

    return 0;
}

// Derive from Scene
// Constructor appropriately