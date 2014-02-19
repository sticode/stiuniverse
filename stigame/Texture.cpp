#include "Texture.h"
#include <iostream>

namespace StiGame
{
    void Texture::initialize(void)
    {
        width = 0;
        height = 0;
        renderer = 0;
        sdlTexture = 0;
        format = SDL_PIXELFORMAT_ABGR8888;
        access = SDL_TEXTUREACCESS_STATIC;
    }

    Texture::Texture(void)
    {
        initialize();
    }

    Texture::Texture(SDL_Texture *m_texture)
    {
        initialize();

        sdlTexture = m_texture;
        query();
    }

    Texture::Texture(SDL_Renderer *m_renderer, int m_width, int m_height)
    {
        //ctor
        initialize();
        width = m_width;
        height = m_height;
        renderer = m_renderer;
        sdlTexture = SDL_CreateTexture(renderer, format, access, width, height);
    }

    Texture::Texture(SDL_Renderer *m_renderer, int m_width, int m_height, Uint32 m_format, int m_access)
    {
        //ctor
        initialize();
        width = m_width;
        height = m_height;
        renderer = m_renderer;
        sdlTexture = SDL_CreateTexture(renderer, format, access, width, height);
    }

    Texture::Texture(SDL_Renderer *m_renderer, const char* img_path)
    {
        //ctor
        initialize();

        renderer = m_renderer;
        SDL_Surface *tmp_sur = IMG_Load(img_path);

        width = tmp_sur->w;
        height = tmp_sur->h;

        sdlTexture = SDL_CreateTextureFromSurface(renderer, tmp_sur);

        SDL_FreeSurface(tmp_sur);
    }

    Texture::Texture(SDL_Renderer *m_renderer, SDL_Surface *surface)
    {
        initialize();
        renderer = m_renderer;
        width = surface->w;
        height = surface->h;

        sdlTexture = SDL_CreateTextureFromSurface(renderer, surface);
    }

    SDL_Texture* Texture::getSDLTexture(void)
    {
        return sdlTexture;
    }

    Uint32 Texture::getFormat(void)
    {
        return format;
    }

    int Texture::getAccess(void)
    {
        return access;
    }

    void Texture::query(void)
    {
        int m_w,m_h,m_access;
        Uint32 m_format;

        if(SDL_QueryTexture(sdlTexture, &m_format, &m_access, &m_w, &m_h) == 0)
        {
            width = m_w;
            height = m_h;
            format = m_format;
            access = m_access;
        }
    }


    void Texture::lock(SDL_Rect *rect, void **pixels, int *pitch)
    {
        SDL_LockTexture(sdlTexture, rect, pixels, pitch);
    }

    void Texture::unlock(void)
    {
        SDL_UnlockTexture(sdlTexture);
    }

    void Texture::setRenderer(SDL_Renderer *m_renderer)
    {
        renderer = m_renderer;
    }

    void Texture::setBlendMode(SDL_BlendMode blendMode)
    {
        SDL_SetTextureBlendMode(sdlTexture, blendMode);
    }

    void Texture::setAlphaMod(Uint8 alpha)
    {
        if(SDL_SetTextureAlphaMod(sdlTexture, alpha) != 0)
        {
            handleError();
        }
    }

    void Texture::setColorMod(Uint8 r, Uint8 g, Uint8 b)
    {
        if(SDL_SetTextureColorMod(sdlTexture, r, g, b) != 0)
        {
            handleError();
        }
    }

    void Texture::renderCopy(SDL_Rect *src, SDL_Rect *dst)
    {
        if(SDL_RenderCopy(renderer, sdlTexture, src, dst) != 0)
        {
            handleError();
        }
    }

    void Texture::renderCopyEx(SDL_Rect *src, SDL_Rect *dst, double angle, SDL_Point *center, SDL_RendererFlip flip)
    {
        if(SDL_RenderCopyEx(renderer, sdlTexture, src, dst, (angle*180)/3.1416, center, flip) != 0)
        {
            handleError();
        }
    }

    void Texture::handleError(void)
    {
        const char* sdl_error = SDL_GetError();
        //temporary need an error handler
        std::cout << sdl_error << std::endl;
    }

    Texture::~Texture()
    {
        //dtor
        SDL_DestroyTexture(sdlTexture);
    }

}
