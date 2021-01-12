## DocumentBuilder
![C++](https://img.shields.io/badge/C++-blue.svg?style=for-the-badge&logo=c%2B%2B)&nbsp;

DocumentBuilder is a console application which allows a user to generate an XML or JSON document from the command line.

## Goal

My goal when creating this application was to utilize the Composite and Builder software design patterns to generate XML and JSON structures.

## How to use it

```
Usage:
    help                   -Prints Usage (this page).
    mode:<JSON|XML>        -Sets mode to JSON or XML. Must be set before creating or closing.
    branch:<name>          -Creates a new branch, assigning it the passed name.
    leaf:<name>:<content>  -Creates a new leaf, assigning the passed name and content.
    close                  -Closes the current branch, as long as it is not the root.
    print                  -Prints the doc in its current state to the console.
    exit                   -Exits the application.
    export                 -Exports the written document to a file
```
Initially, you must set the mode to either JSON or XML (e.g. `mode:json`). All inputs are case insensitive.

## Example:

![](https://i.imgur.com/FzE4pjA.png)

This generates a file called `preview.json` with the following content:

```javascript
{
    "b1" :
    {
        "name1" : "text1",
        "name2" : "text2",
        "b2" :
        {
            "b3" :
            {
                "name3" : "text3"
            },
            "b4" :
            {
                "name4" : "text4"
            }
        }
    }
}
```

## Next Steps

The next feature I will be adding is the ability to add arrays to the JSON/XML structures.
