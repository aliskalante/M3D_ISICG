#version 450 core

<<<<<<< HEAD
in vec3 vColor;
=======
in vec3 outColor; 
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
out vec4 FragColor;

uniform float luminosite;

<<<<<<< HEAD
void main()
{
    FragColor = vec4(vColor * luminosite, 1.0);
=======
void main() {
    FragColor = vec4(outColor*luminosite, 1.0); 
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
}
