#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/component_wise.hpp>


#include <memory>


namespace rt {
    struct HitRecord {
        float t;
        std::shared_ptr<struct Material> mat;
        glm::vec3 p;
        glm::vec3 normal;
    };

    class Material {
        public:
        
        virtual ~Material() {}
        virtual bool scatter(const struct Ray &r_in, const struct HitRecord &rec, glm::vec3 &attenuation, struct Ray &scattered, bool true_lambertian) const = 0;
    };

    class Hitable {
    public:
        virtual bool hit(const struct Ray &r, float t_min, float t_max, struct HitRecord &rec) const = 0;
    };
}; // namespace rt
