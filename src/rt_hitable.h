#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/component_wise.hpp>


#include <memory>

namespace rt {
    class Material {
        public:
        
          virtual ~Material() {}
          virtual bool scatter(const Ray &r_in, const struct HitRecord &rec, glm::vec3 &attenuation, Ray &scattered, const RTContext& rtx) const = 0;
      };


struct HitRecord {
    float t;
    std::shared_ptr<Material> mat;
    glm::vec3 p;
    glm::vec3 normal;
};

class Hitable {
public:
    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const = 0;
};



} // namespace rt
