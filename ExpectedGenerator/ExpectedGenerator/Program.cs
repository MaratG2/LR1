// See https://aka.ms/new-console-template for more information

using System.Globalization;

const string path = "..\\..\\..\\..\\..\\tests\\data";
DirectoryInfo dinfo = new DirectoryInfo(path);
FileInfo[] files = dinfo.GetFiles("*.txt");
foreach(FileInfo file in files)
{
    if (file.Name.Contains("Test") && !file.Name.Contains("expected"))
        GenerateExpected(file);
}

void GenerateExpected(FileInfo test)
{
    List<float> arr = [];
    string str;
    double value = 0.0;
    int len = 0;
    bool isLastInBounds = false;
    
    using (TextReader reader = test.OpenText())
    {
        while ((str = reader.ReadLine()) != null)
        {
            value = double.Parse(str, CultureInfo.InvariantCulture.NumberFormat);
            
            isLastInBounds = false;
            bool isInBounds = (float)value >= -340282347000000000000000000000000000000.000000 &&
                              (float)value <= 340282347000000000000000000000000000000.000000;
            
            if(isInBounds)
            {
                arr.Add((float)value);
                isLastInBounds = true;
            }
            len++;
        }
    }

    Pair<float, float> cs = new (Single.NaN, Single.NaN);
    if (arr.Count > 0 && arr.Count >= len - 1 && isLastInBounds)
    {
        cs.second = arr.Last();
        arr.RemoveAt(arr.Count - 1);
        if (arr.Count >= len - 1)
        {
            cs.first = arr.Last();
            arr.RemoveAt(arr.Count - 1);
        }
    }
    else if (arr.Count > 0 && arr.Count >= len - 1 && !isLastInBounds)
    {
        cs.first = arr.Last();
        arr.RemoveAt(arr.Count - 1);
    }
    else if (arr.Count == 2 && len > 2)
    {
        cs.second = arr.Last();
        arr.RemoveAt(arr.Count - 1);
        cs.first = arr.Last();
        arr.RemoveAt(arr.Count - 1);
    }
    else if (arr.Count == 1 && len > 1 && isLastInBounds)
    {
        cs.second = arr.Last();
        arr.RemoveAt(arr.Count - 1);
    }
    else if (arr.Count == 1 && len > 1 && !isLastInBounds)
    {
        cs.first = arr.Last();
        arr.RemoveAt(arr.Count - 1);
    }
    
    List<float> res = SolveProblem(arr, cs);

    string name = test.FullName.Replace(".txt","") + "_expected.txt";
    using (StreamWriter w = File.CreateText(name))
    {
        foreach (var r in res)
        {
            w.WriteLine(r.ToString(CultureInfo.InvariantCulture));
        }
    }
}

bool floatEquals(float a, float b, int precision = 6) 
{
    float epsilon = MathF.Pow(10, -precision);
    return Math.Abs(a - b) < epsilon;
}

bool floatLess(float a, float b, int precision = 6)
{
    float epsilon = MathF.Pow(10, -precision);
    return b - a > epsilon;
}

bool floatMore(float a, float b, int precision = 6)
{
    float epsilon = MathF.Pow(10, -precision);
    return a - b > epsilon;
}

List<float> SolveProblem(List<float> arr, Pair<float, float> cs)
{
    Pair<int, float> min = new (-1, Single.NaN);
    List<float> res = arr;
    
    if (arr.Count > 1024)
        return res;

    if (floatMore(cs.first, cs.second))
        return res;
    
    int i = 0;
    while (i < arr.Count)
    {
        if (floatMore(arr[i], cs.first))
        {
            if (floatLess(arr[i], cs.second))
            {
                if (floatLess(arr[i], min.second))
                {
                    min.first = i;
                    min.second = arr[i];
                }
                else if (min.first == -1)
                {
                    min.first = i;
                    min.second = arr[i];
                }
            }
        }
        i++;
    }

    i = 0;
    while (i < arr.Count)
    {
        if (floatMore(res[i], cs.first))
        {
            if (floatLess(res[i], cs.second))
                res[i] = min.second;
        }
        i++;
    }
    return res;
}

public class Pair<T, U> {
    public Pair() {
    }

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T first { get; set; }
    public U second { get; set; }
};