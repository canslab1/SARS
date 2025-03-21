# How Do Viruses Spread? Can We Predict the Next Pandemic?
Whenever a new infectious disease emerges, the questions people ask most often are: "How fast will the outbreak spread?" and "Do prevention measures really work?" From SARS in 2003 to the H1N1 flu in 2009 and COVID-19 in 2020, we have witnessed time and again how viruses can rapidly spread and disrupt societies worldwide. However, accurately predicting the course of an epidemic is more complex than simply calculating the basic reproduction number (R₀). The spread of a virus is influenced not just by biological factors but also by human behavior.

Traditional epidemiological models often assume that people move randomly and that contact between individuals is equally likely at all times. But in reality, our daily activities follow clear patterns—we commute to work, attend school, shop at the same stores, and return home. Recognizing this, we developed a Small-World Epidemiological Model, incorporating the concept of "Mirror Identity", to better simulate how real-world epidemics unfold.

A Mirror Identity represents the places we frequently visit—our home, office, school, gym, favorite coffee shop, and more. These places serve as fixed points in our social network where we regularly interact with the same groups of people. From a virus’s perspective, these locations are critical transmission hubs. For example, if you are an office worker, you likely interact with the same colleagues every day, while your family members interact with a different set of people. These small-world connections influence how a virus spreads through society, making transmission patterns very different from what traditional random-contact models predict.

Using this model, we successfully simulated the SARS outbreaks in Singapore, Taipei, and Toronto, allowing us to analyze the effectiveness of various public health measures. The results showed that reducing public contact and implementing home quarantine early significantly slowed the spread of the virus and even helped prevent major outbreaks. In contrast, relying solely on temperature screening or hospital isolation was insufficient to contain the epidemic, as many infected individuals transmitted the virus before showing symptoms. This aligns with what we observed in both COVID-19 and H1N1, where delayed or ineffective intervention led to recurring waves of infection.

Our research is not just about past epidemics—it is also about preparing for the future. History has shown us that new viruses will continue to emerge. From H1N1 in 2009 to MERS in 2012 and COVID-19 in 2020, new challenges appear every few years. The key question is: How do we respond when the next pandemic strikes? By improving our ability to model disease transmission, we can anticipate the most likely spread patterns and design more effective prevention strategies before an outbreak spirals out of control.

To make this research accessible to a wider audience, we have developed an interactive simulation system that is available for download. Users can adjust various parameters—mask usage rates, quarantine policies, social distancing measures—and observe how different strategies impact the course of an epidemic. This tool is valuable not only for epidemiologists and public health experts but also for policymakers, educators, and individuals who want to understand why certain prevention strategies work better than others.

Pandemic control is not just a medical issue—it is a social behavior issue. By using realistic models and simulations, we can develop better strategies for containing future outbreaks and protecting public health. If you're interested in this research, download our paper and simulation tool today and join us in exploring how viruses spread!

# 病毒是怎麼傳播的？我們能預測下一場疫情嗎？
每當有新興傳染病爆發，大家最關心的問題往往是：「疫情到底會擴散多快？」「防疫政策真的有效嗎？」從 2003 年的 SARS、2009 年的 H1N1 流感，到 2020 年的 COVID-19，我們已經多次見識到病毒如何迅速擴散，衝擊全球。然而，想要準確預測疫情的發展，遠比單純計算 R 值（基本傳染數）更困難。因為影響病毒傳播的，除了生物特性，還有人類的行為模式。

傳統的流行病學模型大多假設人們是隨機移動的個體，接觸到感染者就可能生病。但現實中，我們的日常活動是有規律的：每天固定去上班、上課、買菜、回家，而不是隨機亂走。因此，我們在研究 SARS 傳播時，提出了一種新的 「小世界流行病模型」(Small-World Epidemiological Model)，並引入了 「社會分身點」(Mirror Identity) 的概念，來更準確地模擬疫情發展。

所謂「社會分身點」，指的是我們每天重複造訪的地點，例如家、辦公室、學校、餐廳、醫院等。這些場所不只是我們活動的據點，也是病毒傳播的重要節點。舉個例子，如果你是一名上班族，那麼你每天可能會和固定的一群同事接觸，而你的家人則會與另一群人接觸。這些接觸點組成了一個小世界網絡，讓病毒在社會中擴散的方式變得不同於傳統隨機模型所描述的那樣。

我們利用這個模型，成功模擬了 SARS 在新加坡、台北和多倫多的傳播情況，並進一步測試了不同防疫政策的效果。結果顯示，若能及早實施 減少公共接觸 和 家庭隔離，能夠大幅降低病毒的傳播速度，甚至有效抑制疫情。但如果僅依賴 測量體溫 或 醫院隔離，則可能不足以阻止病毒的擴散，因為許多感染者在症狀出現前就已經傳播病毒了。這與我們在 COVID-19 和 H1N1 疫情中看到的情況類似，當防疫措施不夠及時或未能針對關鍵接觸點進行干預時，疫情就容易反覆爆發。

這項研究的價值不僅限於 SARS 或 COVID-19，還能幫助我們應對未來的流行病。歷史告訴我們，新的病毒總會不斷出現，從 2009 年的 H1N1，到 2012 年的 MERS，再到 2020 年的新冠疫情，每隔幾年就會有新的挑戰。當下一場疫情發生時，我們該如何應對？透過更精確的模擬，我們可以更好地預測病毒的傳播路徑，並提前制定最有效的防疫策略，避免重蹈覆轍。

為了讓更多人能夠親自體驗這個模型，我們開發了一個模擬系統，開放下載。使用者可以調整不同的條件，例如：口罩配戴率、隔離政策、社交距離措施，甚至可以模擬不同國家的應對策略，看看哪種方式最有效。這不僅對公共衛生專家有幫助，一般人也能透過模擬，了解為什麼某些防疫政策比其他方法更有效，甚至可以用來制定學校或職場的防疫對策。

疫情的控制不只是醫學問題，更是一個社會行為問題。透過更貼近現實的數學模型與模擬，我們可以找到更有效的防疫策略，也能為未來的疫情做好準備。如果你對這樣的研究感興趣，現在就來下載我們的論文與模擬程式，一起探索病毒如何傳播吧！
