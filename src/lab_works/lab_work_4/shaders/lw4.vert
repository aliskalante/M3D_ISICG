#version 450

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;

// Matrices et paramètres uniformes
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;
uniform vec3 cameraPosition;

out vec3 transformedNormal;
out vec3 viewDirection;

void main()
{
    // Calcul de la position finale du sommet
    gl_Position = modelViewProjectionMatrix * vec4(vertexPosition, 1.0);

    // Position du fragment dans l'espace monde
    vec3 worldPosition = vec3(modelMatrix * vec4(vertexPosition, 1.0));

    // Transformation de la normale
    transformedNormal = normalize(normalMatrix * vertexNormal);

    // Direction vue depuis la caméra
    viewDirection = cameraPosition - worldPosition;
}
