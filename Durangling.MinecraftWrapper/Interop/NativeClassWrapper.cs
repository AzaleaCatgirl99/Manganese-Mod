namespace Minecraft.Interop;

public abstract unsafe class NativeClassWrapper<T>(T* handle) : INativeWrapper where T : unmanaged
{
    public bool IsValid => Handle != null;
    public readonly T* Handle = handle;
}