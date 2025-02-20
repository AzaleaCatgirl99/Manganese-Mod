using System.Diagnostics;
using System.Runtime.CompilerServices;

namespace Durangling.Utilities;

public static class Logger
{
    public enum Level
    {
        Debug,
        Info,
        Warning,
        Error,
        Fatal
    }

    public static void Write(Level level, string message, [CallerLineNumber] int lineNumber = 0)
    {
        string formatted = $"{DateTime.Now:T} [{GetCallerName()}:{lineNumber}]: {message}";
        
        Debug.WriteLine(formatted);
        
        Console.ForegroundColor = level switch
        {
            Level.Debug => ConsoleColor.DarkYellow,
            Level.Info => ConsoleColor.Blue,
            Level.Warning => ConsoleColor.Yellow,
            Level.Error => ConsoleColor.Red,
            Level.Fatal => ConsoleColor.DarkRed,
            _ => ConsoleColor.Green
        };
        Console.WriteLine(formatted);
        Console.ResetColor();
    }

    private static string GetCallerName()
    {
        StackTrace st = new();
        StackFrame? sf = st.GetFrame(2); // 0 - GetCurrentMethod; 1 - Write; 2 - actual method
        if (sf == null)
        {
            return "Unknown";
        }
        
        DiagnosticMethodInfo? dmi = DiagnosticMethodInfo.Create(sf);
        if (dmi == null)
        {
            return "Unknown";
        }

        return $"{dmi.DeclaringTypeName}.{dmi.Name}";
    }
}