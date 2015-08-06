#version 130

in vec3 position;

out vec3 color;

void main(void){

    glPosition = vec4(position, 1.0);
    
    color = vec3(position.x + 1.0, 1.0, position.y + 1.0);
}


