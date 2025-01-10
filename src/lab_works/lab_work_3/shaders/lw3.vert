<<<<<<< HEAD
#version 450 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;

out vec3 fragColor;

layout(location = 0) uniform mat4 uViewMatrix;
layout(location = 1) uniform mat4 uProjectionMatrix;
layout(location = 2) uniform mat4 uModelMatrix;

void main()
{
    fragColor = inColor;
    gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(inPosition, 1.0);
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
