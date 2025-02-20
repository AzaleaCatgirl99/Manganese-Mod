namespace Durangling.Modding;

public readonly struct ModDetails
{
    public readonly string Id;
    public readonly string Name;
    public readonly Version Version;

    public ModDetails(string id, string name, Version version)
    {
        Id = id.ToLowerInvariant();
        Name = name;
        Version = version;
    }
}