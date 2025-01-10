<<<<<<< HEAD
#version 450 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vColor;

uniform float uTranslationX;

void main()
{
    gl_Position = vec4(aVertexPosition.x + uTranslationX, aVertexPosition.y, 0.0, 1.0);
    vColor = aVertexColor;
}
=======
#version 450
layout( location= 0) in vec2 aVertexPosition; 
layout(location=1)  in vec3 acolor;

uniform float uTranslationX;

out vec3 outColor;
void main() {
	gl_Position = vec4(aVertexPosition.x+uTranslationX,aVertexPosition.y, 0.0, 1.0);
	outColor=acolor ;
	}
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
