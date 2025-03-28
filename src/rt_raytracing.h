#pragma once


#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "rt_box.h"
#include "rt_sphere.h"
#include "rt_triangle.h"


namespace rt {

    struct Scene {
        Sphere ground;
        std::vector<Sphere> spheres;
        std::vector<Box> boxes;
        std::vector<Triangle> mesh;
        Box mesh_bbox;
    };
    extern Scene g_scene;

struct RTContext {
    int width = 500;
    int height = 500;
    std::vector<glm::vec4> image;
    bool freeze = false;
    int current_frame = 0;
    int current_line = 0;
    int max_frames = 1000;
    int max_bounces = 1;
    float epsilon = 2e-4f;
    glm::mat4 view = glm::mat4(1.0f);
    glm::vec3 ground_color = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 sky_color = glm::vec3(0.5f, 0.7f, 1.0f);
    bool show_normals = true;
    // Add more settings and parameters here
    // ...
    std::shared_ptr<rt::Material> material_mesh;
    glm::vec3 mesh_albedo = glm::vec3(1.0f);
    int mesh_material = 0;
    bool anti_aliasing = true;
    bool true_lambertian = false;
};

void setupScene(RTContext &rtx, const char *mesh_filename);
void updateImage(RTContext &rtx);
void resetImage(RTContext &rtx);
void resetAccumulation(RTContext &rtx);

};  // namespace rt
