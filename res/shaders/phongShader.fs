#version 330 core

in vec2 texFragCoord;
in vec3 position_cameraspace;
in vec3 normal_cameraspace;
in int texToUse;

uniform sampler2D textureSampler;
uniform mat4 V;

//Light properties
uniform vec3 ambientIntensity;
uniform vec3 lightPos;
uniform vec3 lightIntensity;

//Material properties
uniform vec3 ambientCoeff;
uniform vec3 diffuseCoeff;
uniform vec3 specularCoeff;
uniform float phongExp;

out vec3 colour;

void main(void) {
	vec3 s = normalize(V * vec4(lightPos, 0)).xyz;
    vec3 v = normalize(-position_cameraspace);
    vec3 r = normalize(reflect(-s, normal_cameraspace));

	vec3 ambient = ambientIntensity * ambientCoeff;
    vec3 diffuse = max(lightIntensity * diffuseCoeff * dot(normal_cameraspace, s), 0);
    vec3 specular;
    if (dot(normal_cameraspace, s) > 0)
        specular = max(lightIntensity * specularCoeff * pow(dot(r,v), phongExp), 0);
    else
        specular = vec3(0.0);

    colour = (texture( textureSampler, texCoordFrag ).rgb)*(ambient + diffuse) + specular;
}