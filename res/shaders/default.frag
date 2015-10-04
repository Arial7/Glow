#version 130

in vec4 vs_position;
in vec4 vs_color;

uniform mat4 modelview_matrix;

void main(void){
    gl_FragColor = vs_color;
    mat4 mvmat = modelview_matrix;
}
