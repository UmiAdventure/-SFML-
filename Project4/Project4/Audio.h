#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <optional>             // 用于 lazy sf::Sound

// ─────────── 短音效 ────────────────────────────────
class Audio
{
public:
    Audio() = default;          // 现在可默认构造

    bool load(const std::string& file)
    {
        if (!buffer.loadFromFile(file)) return false;
        sound.emplace(buffer);  // 延迟生成 sf::Sound
        return true;
    }
    void play() { if (sound) sound->play(); }
    bool isPlaying() const
    {
        return sound &&
            sound->getStatus() == sf::SoundSource::Status::Playing;
    }

private:
    sf::SoundBuffer               buffer;
    std::optional<sf::Sound>      sound;
};

// ─────────── 背景音乐 ───────────────────────────────
class MusicPlayer
{
public:
    bool load(const std::string& file) { return music.openFromFile(file); }
    void play(bool loop = true) { music.setLooping(loop); music.play(); }
    void stop() { music.stop(); }
    bool isPlaying() const
    {
        return music.getStatus() == sf::SoundSource::Status::Playing;
    }

private:
    sf::Music music;
};

