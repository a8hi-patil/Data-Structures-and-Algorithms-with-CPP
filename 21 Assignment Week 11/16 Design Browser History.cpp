class BrowserHistory
{
    stack<string> brwsrStack, fwdStack;

public:
    BrowserHistory(string homepage) { brwsrStack.push(homepage); }

    void visit(string url)
    {
        while (!fwdStack.empty())
            fwdStack.pop();
        brwsrStack.push(url);
    }

    string back(int steps)
    {
        while (steps--)
        {
            if (brwsrStack.size() > 1)
            {
                fwdStack.push(brwsrStack.top());
                brwsrStack.pop();
            }
            else
            {
                break;
            }
        }
        return brwsrStack.top();
    }

    string forward(int steps)
    {
        while (steps--)
        {
            if (!fwdStack.empty())
            {
                brwsrStack.push(fwdStack.top());
                fwdStack.pop();
            }
            else
            {
                break;
            }
        }
        return brwsrStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */