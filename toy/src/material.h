#pragma once

#include "vulkan_context.h"
#include "basic_pipeline.h"

class Texture;
class TextureCubemap;

class Material {
public:
	~Material();

	void init(VulkanContext& ctx, BasicPipeline& pipeline, Texture& texture);
	void init(VulkanContext& ctx, BasicPipeline& pipeline, TextureCubemap& texture);
	void bind(VkCommandBuffer command_buffer);
	MaterialUniforms& ref_uniforms();

	void destroy();

private:
	VulkanContext* m_ctx;
	BasicPipeline* m_pipeline;
	Texture* m_texture;
	TextureCubemap* m_texture_cubemap;
	VkDescriptorSet m_descriptor_set;
	VulkanBuffer m_buffer;
	MaterialUniforms m_material_uniforms;
};