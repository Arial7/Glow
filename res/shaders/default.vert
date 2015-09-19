#version 130

in vec4 position;
in vec4 color;

uniform mat4 projection_matrix;
uniform mat4 modelview_matrix = mat4(1.0);
uniform vec3 tranlation;

out vec4 vs_position;
out vec4 vs_color;


void main(void){
    gl_FrontColor = vec4(1.0, 1.0, 1.0, 1.0);
    gl_Position = /*projection_matrix * */ vec4(translation, 1.0) * gl_Vertex;
    vs_color = vec4(1.0, 1.0, 1.0, 1.0);
    vs_position = vec4(position, 1.0);
}
