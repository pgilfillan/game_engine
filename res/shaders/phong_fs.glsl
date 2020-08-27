#version 330 core

in vec2 texCoord;
in vec4 positionView;
in vec3 normalView;

uniform sampler2D textureSampler;

//Light properties
uniform vec3 ambientIntensity;
uniform vec4 lightPos; // Last entry is 0 for directional, 1 for positional
uniform vec3 lightIntensity;

//Material properties
uniform vec3 ambientCoeff;
uniform vec3 diffuseCoeff;
uniform vec3 specularCoeff;
uniform float phongExp;

out vec3 colour;

void main(void) {
    vec3 s = normalize(lightPos - positionView).xyz;
    vec3 v = normalize(-positionView.xyz);
    vec3 r = normalize(reflect(-s, normalView));

	vec3 ambient = ambientIntensity * ambientCoeff;
    vec3 diffuse = max(lightIntensity * diffuseCoeff * dot(normalView, s), 0);
    vec3 specular;
    if (dot(normalView, s) > 0)
        specular = max(lightIntensity * specularCoeff * pow(dot(r, v), phongExp), 0);
    else
        specular = vec3(0.0);

    colour = (texture(textureSampler, texCoord).rgb) * (ambient + diffuse) + specular;
    //colour = texture(textureSampler, texCoord).rgb;
}