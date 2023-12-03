#include "Start.h"
#include "Utility.h"


#define LEVEL_WIDTH 14
#define LEVEL_HEIGHT 8

void draw_text(ShaderProgram* program, GLuint font_texture_id, std::string text, float screen_size, float spacing, glm::vec3 position);
const int FONTBANK_SIZE = 8;

unsigned int START_DATA[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
Start::~Start()
{
    delete[] m_state.enemies;
    delete    m_state.player;
    delete    m_state.map;
    Mix_FreeChunk(m_state.jump_sfx);
    Mix_FreeMusic(m_state.bgm);
}

void Start::initialise() {

    m_state.next_scene_id = -1;
    GLuint map_texture_id = Utility::load_texture("tileset.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, START_DATA, map_texture_id, 1.0f, 4, 1);
    is_a_main_scene = 0;
}


void Start::update(float delta_time){}

void Start::render(ShaderProgram* program) {

    GLuint message_texture_id = Utility::load_texture("alphabet.png");
    Utility::draw_text(program, message_texture_id, "press enter to start", 1.0f, 0.1f, glm::vec3(5.0f, 0.0f, 0.0f));
    m_state.map->render(program);
}


