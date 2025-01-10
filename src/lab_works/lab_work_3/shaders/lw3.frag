#version 450 core

<<<<<<< HEAD
in vec3 fragColor;

out vec4 outColor;

void main()
{
    outColor = vec4(fragColor, 1.0);
}
=======
in vec3 outColor; 
out vec4 FragColor;

uniform float luminosite;

void main() {
    FragColor = vec4(outColor*luminosite, 1.0); 
}
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
