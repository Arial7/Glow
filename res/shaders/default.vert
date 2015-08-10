#version 130

in vec3 position;

out vec3 color;

void main(void){
    gl_FrontColor = vec4(position.x + 1.0, 0.5, position.y + 1.0, 1.0);
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    color = vec3(position.x + 1.0, 0.5, position.y );
}


