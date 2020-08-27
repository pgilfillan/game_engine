#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

uniform mat4 MVP;
uniform mat4 MV;

out vec2 texCoord;
out vec4 positionView;
out vec3 normalView;

void main() {
    gl_Position = MVP * vec4(vertexPosition, 1);
    texCoord = uv;
    positionView = MV * vec4(vertexPosition, 1);
    normalView = normalize(MV * vec4(normal, 0)).xyz;
}