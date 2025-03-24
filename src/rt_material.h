#pragma once

#include <functional>

#include "cg_utils2.h"
#include "rt_hitable.h"
#include "rt_ray.h"
#include "rt_raytracing.h"


namespace rt {
    class Lambertian : public Material {
     public:
        Lambertian(const glm::vec3 &a) : albedo(a) {}

        bool scatter(const Ray &r_in, const HitRecord &rec, glm::vec3 &attenuation, Ray &scattered, const RTContext& rtx) const override
        {

            glm::vec3 direction = rtx.true_lambertian ? rec.normal + cg::helpers::random_unit_vector() : cg::helpers::random_unit_vector_on_hemisphere(rec.normal);
            if (cg::helpers::near_zero(direction)) {
                direction = rec.normal;
            }

            scattered = Ray(rec.p, direction);
            attenuation = albedo;
            return true;
        }
     private:
        glm::vec3 albedo;
    };

    class Metal : public Material {
        public:
          Metal(const glm::vec3& albedo) : albedo(albedo) {}
      
          bool scatter(const Ray &r_in, const HitRecord &rec, glm::vec3 &attenuation, Ray &scattered, const RTContext& rtx) const override {
              glm::vec3 reflected = cg::helpers::reflect(r_in.direction(), rec.normal);
              scattered = Ray(rec.p, reflected);
              attenuation = albedo;
              return true;
          }
      
        private:
          glm::vec3 albedo;
      };
};