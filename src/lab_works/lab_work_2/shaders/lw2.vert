#version 450
layout( location= 0) in vec2 aVertexPosition; 
layout(location=1)  in vec3 acolor;

uniform float uTranslationX;

out vec3 outColor;
void main() {
	gl_Position = vec4(aVertexPosition.x+uTranslationX,aVertexPosition.y, 0.0, 1.0);
	outColor=acolor ;
	}