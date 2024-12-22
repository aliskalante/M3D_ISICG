#version 450 core

in vec3 outColor; 
out vec4 FragColor;

uniform float luminosite;

void main() {
    FragColor = vec4(outColor*luminosite, 1.0); 
}