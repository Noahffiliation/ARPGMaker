import pytest
import ARPGMaker
import os

# Constants for testing
RES_X = 800
RES_Y = 600
TILE_SIZE = 32
TITLE = "Test Window"

@pytest.fixture(scope="module", autouse=True)
def init_engine():
    """Initialize the engine once for the entire test session."""
    # Check for headless environment
    if os.environ.get("GITHUB_ACTIONS") == "true" and not os.environ.get("DISPLAY"):
        pytest.skip("Skipping engine initialization in headless CI environment without DISPLAY")
        return

    try:
        # ARPGMaker.init(RES_X, RES_Y, TILE_SIZE, TITLE) # This opens a window, might fail in headless
        # If init is required for other functions to work (like initializing demoMap), we MUST run it.
        # If it fails, we skip.
        ARPGMaker.init(RES_X, RES_Y, TILE_SIZE, TITLE)
    except Exception as e:
        pytest.skip(f"Could not initialize engine (likely no display): {e}")

def test_entity_creation_and_removal():
    """Test creating and removing entities."""
    # Test multiple creations
    id1 = ARPGMaker.createEntity(100, 100, 10)
    id2 = ARPGMaker.createEntity(200, 200, 20)
    assert id1 != id2
    assert id1 >= 0
    assert id2 >= 0

    # Test getters
    assert ARPGMaker.getEntityPositionX(id1) == 100
    assert ARPGMaker.getEntityPositionY(id1) == 100
    assert ARPGMaker.getEntityPositionX(id2) == 200
    assert ARPGMaker.getEntityPositionY(id2) == 200

    # Remove entity
    ARPGMaker.remEntity(id1)
    # Accessing removed entity might be undefined or crash, or return garbage.
    # Validating removal is hard without a specific API to check existence.
    # But we can verify it doesn't crash.

def test_entity_movement_extensive():
    """Test standard and fractional movement."""
    entity_id = ARPGMaker.createEntity(0, 0, 10)

    # Move positive
    ARPGMaker.move(entity_id, 50, 50)
    assert ARPGMaker.getEntityPositionX(entity_id) == 50
    assert ARPGMaker.getEntityPositionY(entity_id) == 50

    # Move negative
    ARPGMaker.move(entity_id, -25, -25)
    assert ARPGMaker.getEntityPositionX(entity_id) == 25
    assert ARPGMaker.getEntityPositionY(entity_id) == 25

    # Move fractional (movef)
    # x += 10/2 = 5 -> 25 + 5 = 30
    # y += 20/4 = 5 -> 25 + 5 = 30
    ARPGMaker.movef(entity_id, 10, 2, 20, 4)
    assert ARPGMaker.getEntityPositionX(entity_id) == 30
    assert ARPGMaker.getEntityPositionY(entity_id) == 30

def test_collision_logic():
    """Test circle collision logic."""
    # Note: circleCollide depends on texture size.
    # If no texture is loaded, size might be 0 or random.
    # We can try to load a dummy texture if we had a file.
    # Assuming default or robust handling (which we probably don't have yet),
    # this test might be risky but let's try.

    # Creating a dummy texture file
    with open("test_tex.png", "wb") as f:
        f.write(b"\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x20\x00\x00\x00\x20\x08\x06\x00\x00\x00sNz\xf4\x00\x00\x00\x01sRGB\x00\xae\xce\x1c\xe9\x00\x00\x00\x04gAMA\x00\x00\xb1\x8f\x0b\xfca\x05\x00\x00\x00\tpHYs\x00\x00\x0e\xc3\x00\x00\x0e\xc3\x01\x95+\x0e\x1b\x00\x00\x00\x07tIME\x07\xe6\x02\x08\x11\x37\x33\x52\x02\xec\xb9\x00\x00\x00\x19tEXtComment\x00Created with GIMP\x57\x81\x0e\x17\x00\x00\x00\x0cIDAT\x18\xd3c\xf8\xff\xff?\x00\x05\xfe\x02\xfe\xa7\x91\x06\xa0\x00\x00\x00\x00IEND\xaeB`\x82")
        # Minimal valid PNG (32x32)

    try:
        ARPGMaker.loadTexture("test_tex.png")

        id1 = ARPGMaker.createEntity(100, 100, 10)
        ARPGMaker.setTexture(id1, "test_tex.png")

        id2 = ARPGMaker.createEntity(105, 100, 10) # 5px apart
        ARPGMaker.setTexture(id2, "test_tex.png")

        # Radii are 10. Distance is 5. Collision should be true.
        assert ARPGMaker.circleCollide(id1, id2) == 1

        id3 = ARPGMaker.createEntity(200, 200, 10)
        ARPGMaker.setTexture(id3, "test_tex.png")

        # Distance > 20. Collision should be false.
        assert ARPGMaker.circleCollide(id1, id3) == 0

    finally:
        if os.path.exists("test_tex.png"):
            os.remove("test_tex.png")

def test_map_initialization():
    """Test map creation functions."""
    ARPGMaker.createMap(32, 20, 20)
    # Just verifies it runs without error.

def test_input_helpers():
    """Test input helper functions."""
    # These rely on window state/events, might return defaults in test.
    # Just ensure they are callable.
    ARPGMaker.mousePositionX()
    ARPGMaker.mousePositionY()
    ARPGMaker.mouseLeftClick()
    ARPGMaker.isKeyPressed("A")
    ARPGMaker.isOpen()

def test_render_wrappers():
    """Test render wrapper functions (callability)."""
    if not ARPGMaker.isOpen():
        pytest.skip("Window not open, cannot test rendering")
    # These interact with SFML window/graphics.
    ARPGMaker.clear()
    ARPGMaker.display()
    # renderEntity requires an entity
    id1 = ARPGMaker.createEntity(0, 0, 10)
    # Needs valid texture...
    with open("test_tex_render.png", "wb") as f:
        f.write(b"\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x20\x00\x00\x00\x20\x08\x06\x00\x00\x00sNz\xf4\x00\x00\x00\x01sRGB\x00\xae\xce\x1c\xe9\x00\x00\x00\x04gAMA\x00\x00\xb1\x8f\x0b\xfca\x05\x00\x00\x00\tpHYs\x00\x00\x0e\xc3\x00\x00\x0e\xc3\x01\x95+\x0e\x1b\x00\x00\x00\x07tIME\x07\xe6\x02\x08\x11\x37\x33\x52\x02\xec\xb9\x00\x00\x00\x19tEXtComment\x00Created with GIMP\x57\x81\x0e\x17\x00\x00\x00\x0cIDAT\x18\xd3c\xf8\xff\xff?\x00\x05\xfe\x02\xfe\xa7\x91\x06\xa0\x00\x00\x00\x00IEND\xaeB`\x82")

    try:
        ARPGMaker.loadTexture("test_tex_render.png")
        ARPGMaker.setTexture(id1, "test_tex_render.png")
        ARPGMaker.renderEntity(id1)
        ARPGMaker.renderEntities() # Iterates all entities
        ARPGMaker.renderImage("test_tex_render.png")
        ARPGMaker.setBackground("test_tex_render.png")
        # ARPGMaker.renderBackground() # Might crash if map tiles not set up with texture?
        # renderBackground iterates tileList. tileList has tiles.
        # Tile texture defaults to...
        # Tile constructor: Entity.cpp line 67 in previous code? No, Tile.cpp.
        # ARPGMaker.setBackground sets texture for all tiles.
        ARPGMaker.renderBackground()
    finally:
        if os.path.exists("test_tex_render.png"):
            os.remove("test_tex_render.png")

def test_audio_wrappers():
    """Test audio wrapper functions."""
    # SFML audio might fail if no audio device, but functions should be callable.
    # createMusic requires a file.
    with open("test.wav", "wb") as f:
        # Minimal WAV
        f.write(b'RIFF$\x00\x00\x00WAVEfmt \x10\x00\x00\x00\x01\x00\x01\x00D\xac\x00\x00\x88X\x01\x00\x02\x00\x10\x00data\x00\x00\x00\x00')

    try:
        mus_id = ARPGMaker.createMusic("test.wav")
        ARPGMaker.playMusic(mus_id)
        ARPGMaker.pauseMusic(mus_id)
        ARPGMaker.stopMusic(mus_id)
        ARPGMaker.setMusicLoop(mus_id, 1)
        ARPGMaker.setMusicVolume(mus_id, 50)
        ARPGMaker.setMusicPitch(mus_id, 1) # Argument must be int according to C implementation?
        # extend.cpp line 319: "ii" format for setMusicPitch (id, pitch).
        status = ARPGMaker.getMusicStatus(mus_id)
        assert status >= 0

        # Sounds
        snd_id = ARPGMaker.createSound("test.wav", 1) # 1 for giveBuffer

        ARPGMaker.playSound(snd_id)
        ARPGMaker.pauseSound(snd_id)
        ARPGMaker.stopSound(snd_id)
        status_snd = ARPGMaker.getSoundStatus(snd_id)
        assert status_snd >= 0
    finally:
        if os.path.exists("test.wav"):
            os.remove("test.wav")
